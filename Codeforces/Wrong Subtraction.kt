fun readLn() = readLine()!! // string line
fun readInt() = readLn().toInt() // single int
fun readStrings() = readLn().split(" ") // list of strings
fun readInts() = readStrings().map { it.toInt() } // list of ints

fun main(args: Array<String>) {
  val (n, k) = readInts()
  var ans = n
  for(i in 1..k){
    if(ans % 10 == 0) ans /= 10
    else ans -= 1
  }
  println(ans)
}