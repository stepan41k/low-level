package main

/*
#include "logic.h"
*/
import "C"

import "fmt"

func main() {
	status := C.get_stats()
	fmt.Printf("Total: %d, Used: %d\n", status.total, status.used)
}