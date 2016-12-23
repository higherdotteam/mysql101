package main

import "fmt"
import "bufio"
import "os"
import "strings"

func main() {
	fmt.Println("mysql101 by higher.team")
	fmt.Println("")
	fmt.Println("http://higher.team is the new MBA")
	fmt.Println("")
	fmt.Println("  HINT: type show tables;")
	fmt.Println("")
	fmt.Print("mysql> ")

	bio := bufio.NewReader(os.Stdin)
	line, _, _ := bio.ReadLine()
	for {
		s := string(line)
		if s == "quit" {
			break
		} else if strings.HasSuffix(s, ";") == false {
			fmt.Println("\nYou forgot the ;\n")
		} else {
			fmt.Println("+-------------------+")
			fmt.Println("| Tables_in_this_db |")
			fmt.Println("+-------------------+")
			fmt.Println("| companies         |")
			fmt.Println("| people            |")
			fmt.Println("| hackernews        |")
			fmt.Println("+-------------------+")
			fmt.Println("3 rows in set (0.00 sec)\n")
		}
		fmt.Print("mysql> ")
		line, _, _ = bio.ReadLine()
	}

}
