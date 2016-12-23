package main

import "fmt"
import "bufio"
import "os"

func main() {
	fmt.Println("mysql101 by higher.team")
	fmt.Println("")
	fmt.Println("http://higher.team is the new MBA")
	fmt.Println("")
	fmt.Print("mysql> ")

	bio := bufio.NewReader(os.Stdin)
	line, _, _ := bio.ReadLine()
	for {
		s := string(line)
		if s == "quit" {
			break
		}
		fmt.Print("mysql> ")
		line, _, _ = bio.ReadLine()
	}

}
