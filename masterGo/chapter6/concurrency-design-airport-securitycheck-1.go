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

func idCheck() int {
	time.Sleep(time.Millisecond * time.Duration(idCheckTmCost))
	fmt.Println("id check done")
	return idCheckTmCost
}

func bodyCheck() int {
	time.Sleep(time.Millisecond * time.Duration(bodyCheckTmCost))
	fmt.Println("body check done")
	return bodyCheckTmCost
}
func xrayCheck() int {
	time.Sleep(time.Millisecond * time.Duration(xRayCheckTmCost))
	fmt.Println("xray check done")
	return xRayCheckTmCost
}

func airportSecurityCheck() int {
	fmt.Println("airportSecurityCheck...")
	total := 0
	total += idCheck()
	total += bodyCheck()
	total += xrayCheck()
	fmt.Println("airportSecurityCheck ok")
	return total
}

func main() {
	total := 0
	passengers := 30
	for i := 0; i < passengers; i++ {
		total += airportSecurityCheck()
	}
	fmt.Println(total)
}
