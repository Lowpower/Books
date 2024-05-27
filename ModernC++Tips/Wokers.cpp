/*
设计方案
1. 数据结构：
  使用数组存储 worker，每个 worker 包含以下信息：
    ID
    当前分配任务数量
    上一轮任务完成时间
    总奖励
2. 任务分配：
  初始化时给每个 worker 分配 x 个任务。
  当超过 51% 的 worker 处于空闲状态时，继续给所有 worker 分配 x 个新任务。
3. 奖励机制：
  每次任务分配时，根据上一轮任务完成效率对前 51% 的 worker 进行奖励。
  如果有多个 worker 同时完成任务，按他们上一轮的完成效率排序。
4. 终止条件：
  系统停止分配任务后，等待所有 worker
完成所有任务，再根据他们的完成顺序进行最终奖励。
5. 实现细节：
  根据任务完成时间和效率对 worker 进行排序和奖励分配。
*/

#include <algorithm>
#include <functional>
#include <iostream>
#include <queue>
#include <vector>

// 定义一个worker类，用于模拟worker的行为,efficiency值越小，效率越高
class Worker {
public:
  Worker(int id) : id(id), lastCompletionTime(0), totalReward(0) {}
  // 添加任务，随机生成效率，并将任务和效率存入队列
  void AddTask(int tasks) {
    int efficiency = 1 + rand() % 10;
    std::cout << id << " efficiency:" << efficiency << std::endl;
    remainingTasks.push(std::make_pair(tasks, efficiency));
  }
  // 处理任务，根据时间和效率减少任务量
  void ProcessTasks(int64_t time) {
    if (!remainingTasks.empty()) {
      auto &task = remainingTasks.front();
      task.first -= static_cast<double>(time) / task.second;
      lastCompletionTime += time;
      lastEfficiency = task.second;
      if (task.first <= 0) {
        remainingTasks.pop();
      }
    }
  }
  // 检查是否还有剩余任务
  bool Empty() const { return remainingTasks.empty(); }
  // 增加奖励
  void AddReward(int amount) { totalReward += amount; }
  // 显示奖励
  void DisPlayReward() const {
    std::cout << "Worker " << id << " reward: " << totalReward << std::endl;
  }

  static bool compare(const Worker &a, const Worker &b) {
    // 任务队列为空的情况
    if (a.remainingTasks.empty() && b.remainingTasks.empty()) {
      if (a.lastCompletionTime == b.lastCompletionTime) {
        return a.lastEfficiency <
               b.lastEfficiency; // 完成时间相同，效率从小到大排序
      }
      return a.lastCompletionTime <
             b.lastCompletionTime; // 完成时间从小到大排序
    }
    // 任务队列不为空的情况
    if (!a.remainingTasks.empty() && !b.remainingTasks.empty()) {
      return a.lastEfficiency < b.lastEfficiency; // 效率从小到大排序
    }
    // 一个为空，一个不为空，空的在前
    return a.remainingTasks.empty();
  };

private:
  int id;
  std::queue<std::pair<double, int>>
      remainingTasks;             // 任务队列，包含任务量和效率
  int64_t lastCompletionTime = 0; // 最后完成时间
  int lastEfficiency = 0;         // 上次执行的的效率
  double totalReward = 0.0;       // 总奖励
};

// worker管理类，用于管理多个worker和任务分配
class WorkerManager {
public:
  WorkerManager(int numWorkers, int tasksPerWorker, int rounds)
      : tasksPerWorker(tasksPerWorker), rounds(rounds) {
    for (int i = 0; i < numWorkers; ++i) {
      // 随机效率
      workers.emplace_back(i);
      workers.back().AddTask(tasksPerWorker);
    }
  }
  // 给所有worker添加任务
  void AddTasks(int tasksPerWorker) {
    for (auto &worker : workers) {
      worker.AddTask(tasksPerWorker);
    }
  }
  // 分配任务
  void DistributeTasks() {
    for (auto &worker : workers) {
      worker.ProcessTasks(1);
    }
  }
  // 奖励worker
  void RewardWorkers() {
    std::stable_sort(workers.begin(), workers.end(), Worker::compare);
    int amount = workers.size();
    for (auto &worker : workers) {
      worker.AddReward(amount--); // 奖励分配
    }
  }
  // 等待所有任务完成
  bool WaitallTasksCompleted() {
    return std::all_of(workers.begin(), workers.end(),
                       [](const Worker &worker) { return worker.Empty(); });
  }
  // 模拟整个工作流程
  void Simulate(int rounds) {
    int currRounds = 1;
    while (currRounds < rounds) {
      DistributeTasks();
      int idleWorkers =
          std::count_if(workers.begin(), workers.end(),
                        [](const Worker &worker) { return worker.Empty(); });
      // 一轮奖励
      if (idleWorkers > workers.size() / 2) {
        RewardWorkers();
        for (const auto &worker : workers) {
          worker.DisPlayReward();
        }
        if (currRounds < rounds) {
          AddTasks(tasksPerWorker);
        }
        ++currRounds;
      }
    }
    // 等待所有任务完成
    while (!WaitallTasksCompleted()) {
      DistributeTasks();
    }
    // 所有任务完成后进行最终奖励
    RewardWorkers();
    for (const auto &worker : workers) {
      worker.DisPlayReward();
    }
  }

private:
  std::vector<Worker> workers; // worker列表
  int tasksPerWorker;          // 每个worker的任务数
  int rounds;                  // 轮次
};

int main() {
  int numWorkers = 4;
  int tasksPerWorker = 5;
  int rounds = 3;

  WorkerManager manager(numWorkers, tasksPerWorker, rounds);
  manager.Simulate(rounds);

  return 0;
}
