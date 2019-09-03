fun readLn() = readLine()!! // string line
fun readInt() = readLn().toInt() // single int
fun readStrings() = readLn().split(" ") // list of strings
fun readInts() = readStrings().map { it.toInt() } // list of ints

fun main(args: Array<String>) {
  val (n, k) = readInts()
  var a = readInts().toTypedArray()
  a.sort()
  if(n == k)println(a[n-1])
  else if(k == 0){
    if(a[0] == 1)println(-1)
    else println(1)
  }
  else if(a[k] != a[k-1])println(a[k-1])
  else println(-1)
}