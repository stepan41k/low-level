package main

/*
#include <stdio.h>
#include <stdlib.h>

void hello_from_c(const char* name) {
	printf("Hello from C, %s\n", name);
}

int add(int a, int b) {
	return a + b;
}
*/
import "C"

import (
	"fmt"
	"unsafe"
)

func main() {
	sum := C.add(10, 20)
	fmt.Println("Sum from C:", sum)

	name := C.CString("Gopher")
	defer C.free(unsafe.Pointer(name))

	C.hello_from_c(name)
}