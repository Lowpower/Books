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
	fmt.Printf("%d id check done", id)
	return idCheckTmCost
}

func bodyCheck(id int) int {
	time.Sleep(time.Millisecond * time.Duration(bodyCheckTmCost))
	fmt.Println("body check done")
	fmt.Printf("%d body check done", id)
	return bodyCheckTmCost
}
func xrayCheck(id int) int {
	time.Sleep(time.Millisecond * time.Duration(xRayCheckTmCost))
	fmt.Printf("%d xray check done", id)
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

func start(id int, f func(int) int, queue <-chan struct{}) <-chan int {
	c := make(chan int)
	go func() {
		total := 0
		for {
			_, ok := <-queue
			if !ok {
				c <- total
				return
			}
			total += f(id)
		}
	}()
	return c
}

func max(x, y int) int {
	if x > y {
		return x
	}
	return y
}

func main() {
	total := 0
	passengers := 30
	c := make(chan struct{})
	c1 := start(1, airportSecurityCheck, c)
	c2 := start(2, airportSecurityCheck, c)
	c3 := start(3, airportSecurityCheck, c)
	for i := 0; i < passengers; i++ {
		c <- struct{}{}
	}
	close(c)
	total = max(<-c1, max(<-c2, <-c3))
	fmt.Println(total)
}
