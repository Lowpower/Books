package main

import (
	"fmt"
	"time"
)

const (
	idCheckTmCost   = 60
	bodyCheckTmCost = 120
	xRayCheckTmCost = 180
)

func idCheck(id int) int {
	time.Sleep(time.Millisecond * time.Duration(idCheckTmCost))
	fmt.Printf("%d id check done\n", id)
	return idCheckTmCost
}

func bodyCheck(id int) int {
	time.Sleep(time.Millisecond * time.Duration(bodyCheckTmCost))
	fmt.Printf("%d body check done\n", id)
	return bodyCheckTmCost
}
func xrayCheck(id int) int {
	time.Sleep(time.Millisecond * time.Duration(xRayCheckTmCost))
	fmt.Printf("%d xray check done\n", id)
	return xRayCheckTmCost
}

func airportSecurityCheck(id int) int {
	fmt.Printf("%d airportSecurityCheck...\n", id)
	total := 0
	total += idCheck(id)
	total += bodyCheck(id)
	total += xrayCheck(id)
	fmt.Printf("%d airportSecurityCheck ok\n", id)
	return total
}

func start(id int, f func(int) int, next chan<- struct{}) (chan<- struct{}, chan<- struct{}, <-chan int) {
	queue := make(chan struct{}, 10)
	quit := make(chan struct{})
	result := make(chan int)

	go func() {
		total := 0
		for {
			select {
			case <-quit:
				result <- total
				return
			case v := <-queue:
				total += f(id)
				if next != nil {
					next <- v
				}
			}
		}
	}()
	return queue, quit, result
}

func max(x, y int) int {
	if x > y {
		return x
	}
	return y
}

func newAirportSecurityCheck(id int, queue <-chan struct{}) {
	go func(id int) {
		fmt.Printf("%d starting...\n", id)
		queue3, quit3, result3 := start(id, xrayCheck, nil)
		queue2, quit2, result2 := start(id, bodyCheck, queue3)
		queue1, quit1, result1 := start(id, idCheck, queue2)
		for {
			select {
			case v, ok := <-queue:
				if !ok {
					close(quit1)
					close(quit2)
					close(quit3)
					total := max(<-result1, max(<-result2, <-result3))
					fmt.Printf("%d done cost: %d\n", id, total)
					return
				}
				queue1 <- v
			}
		}
	}(id)
}

func main() {
	passengers := 30
	queue := make(chan struct{}, 30)
	newAirportSecurityCheck(1, queue)
	newAirportSecurityCheck(2, queue)
	newAirportSecurityCheck(3, queue)
	time.Sleep(time.Second * 5)
	for i := 0; i < passengers; i++ {
		queue <- struct{}{}
	}
	time.Sleep(time.Second * 5)
	close(queue)
	time.Sleep(time.Second * 1000)
}
