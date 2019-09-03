fun main(args: Array<String>) {
  val n: Int = readLine()!!.toInt()
  val s: String = readLine()!!
  val m: MutableMap<String, Int> = mutableMapOf<String, Int>().withDefault {0}
  for(i in 0..n-2){
    m[s.substring(i, i+2)] = m.getValue(s.substring(i, i+2)) + 1;
  }
  var mx = "AA"
  for((key, v) in m){
    if(v > m.getValue(mx)) mx = key
  }
  println(mx)
}