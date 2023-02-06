#### TBB的主要功能：

1. 并行算法
2. 任务调度
3. 并行容器
4. 同步原语
5. 内存分配器
这里主要关注并行算法和任务

#### 并行算法

1. parallel_for 以并行方式遍历一个区间
parallel_for会根据CPU核数将区间分成几部分，然后对每一部分启动一个线程去遍历
```
parallel_for(1, 20000, [](int i){cout << i << endl; });
parallel_for(blocked_range<size_t>(0, 20000), [](blocked_range<size_t>& r)
{
    for (size_t i = r.begin(); i != r.end(); ++i)
        cout << i << endl; 
});
```

2. parallel_do 和 parallel_for_each 将算法应用于一个区间
逻辑和上面是类似的
```
vector<size_t> v;
parallel_do(v.begin(), v.end(), [](size_t i){cout << i << endl; });
parallel_for_each(v.begin(), v.end(), [](size_t i){cout << i << endl; });
```
3. parallel_reduce
类似于map_reduce，但是有区别。它先将区间自动分组，对每个分组进行聚合(accumulate)计算，每组得到一个结果，最后将各组的结果进行汇聚(reduce)。这个算法稍微复杂一点，parallel_reduce(range,identity,func,reduction)，第一个参数是区间范围，第二个参数是计算的初始值，第三个参数是聚合函数，第四个参数是汇聚参数。
```
float ParallelSum(float array [], size_t n) {
    return parallel_reduce(
        blocked_range<float*>(array, array + n),
        0.f,
        [](const blocked_range<float*>& r, float value)->float {
            return std::accumulate(r.begin(), r.end(), value);
    },
        std::plus<float>()
        );
}
```
这个对数组求和的例子就是先自动分组然后对各组中的元素进行聚合累加，最后将各组结果汇聚相加。
4. parallel_pipeline:并行的管道过滤器
数据流经过一个管道，在数据流动的过程中依次要经过一些过滤器的处理，其中有些过滤器可能会并行处理数据，这时就可以用到并行的管道过滤器。举一个例子，比如我要读入一个文件，先将文件中的数字提取出来，再将提取出来的数字做一个转换，最后将转换后的数字输出到另外一个文件中。其中读文件和输出文件不能并兴去做，但是中间数字转换的环节可以并行去做的。parallel_pipeline的原型：
```
parallel_pipeline( max_number_of_live_tokens, 
                   make_filter<void,I1>(mode0,g0) &
                   make_filter<I1,I2>(mode1,g1) &
                   make_filter<I2,I3>(mode2,g2) &
                   ... 
                   make_filter<In,void>(moden,gn) );
```
第一个参数是最大的并行数，我们可以通过&连接多个filter，这些filter是顺序执行的，前一个filter的输出是下一个filter的输入。
parallel_pipeline的基本用法：
```
float RootMeanSquare( float* first, float* last ) {
    float sum=0;
    parallel_pipeline( /*max_number_of_live_token=*/16,       
        make_filter<void,float*>(
            filter::serial,
            [&](flow_control& fc)-> float*{
                if( first<last ) {
                    return first++;
                 } else {
                    fc.stop();
                    return NULL;
                }
            }    
        ) &
        make_filter<float*,float>(
            filter::parallel,
            [](float* p){return (*p)*(*p);} 
        ) &
        make_filter<float,void>(
            filter::serial,
            [&](float x) {sum+=x;}
        )
    );
    return sqrt(sum);
}
```
第一个filter生成数据（如从文件中读取数据等），第二个filter对产生的数据进行转换，第三个filter是对转换后的数据做累加。其中第二个filter是可以并行处理的，通过filter::parallel来指定其处理模式。

5. parallel_sort和parallem_invoke 并行排序和调用

1. parallel_sort:并行排序
```
const int N = 1000000;
float a[N];
float b[N];
parallel_sort(a, a + N);
parallel_sort(b, b + N, std::greater<float>());
```
2. parallel_invoke:并行调用，并行调用多个函数
```
void f();
extern void bar(int);

void RunFunctionsInParallel() {
    tbb::parallel_invoke(f, []{bar(2);}, []{bar(3);} );
}
```

#### TBB任务
task_group表示可以等待或者取消的任务集合
```
task_group g;
g.run([]{TestPrint(); });
g.run([]{TestPrint(); });
g.run([]{TestPrint(); });
g.wait();
```
上面的例子，先把任务添加到task_group中，然后启动相应个数的线程，处理每个分组的任务
tbb自己内部实现了自己的任务调度器，会动态控制工作线程数和任务对象的初始化时机
TBB的任务有很多优点，比如：
task的启动、停止通常比thread更快
task更能匹配有效资源（因为有TBB的任务调度器）
task在编程时使程序员更能专注业务实现而不是底层细节
task实现了负载均衡

更详细的实现细节可以参考书籍：

