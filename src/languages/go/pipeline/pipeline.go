// Package pipeline demonstrates how multiple goroutine sets work on task with stages
// The realistic problem is squaring numbers
package pipeline

import "fmt"

// Function gen takes a variadic number of integers and returns the reader side of channel
func gen(nums ...int) <-chan int {
	out := make(chan int)
	go func() {
		for _, n := range nums {
			out <- n
		}
		// channel should be manually closed, otherwise block the reader go-routines
		close(out)
	}()
	return out
}

// Function sq receives integers from reader channel, do square and returns the writer channel
func sq(in <-chan int) <-chan int {
	out := make(chan int)
	go func() {
		// an reader-side channel can be iterated over using range
		for n := range in {
			out <- n * n
		}
		// channel "in" is closed
		close(out)
	}()
	return out
}

func LaunchPipeline(nums ...int) []int {
	first := gen(nums...)
	second := sq(first)
	var result []int
	// The main go-routine is blocked by this loop over channel "second"
	for n := range second {
		fmt.Printf("Result: %d\n", n)
		result = append(result, n)
	}
	return result
}
