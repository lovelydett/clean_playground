package main

import (
	"fmt"

	"github.com/lovelydett/clean_playground/src/language/go/pipeline"
)

func main() {
	fmt.Println("Pipeline demo")

	nums := make([]int, 100)

	for i := 0; i < len(nums); i++ {
		nums[i] = i + 1
	}

	result := pipeline.LaunchPipeline(nums...)

	fmt.Println(result)
}
