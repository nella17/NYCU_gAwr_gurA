import java.util.*
import kotlin.math.*
private class Scanner {
    val lines = java.io.InputStreamReader(System.`in`).readLines()
    var curLine = 0
    var st = StringTokenizer(lines[0])
    fun next(): String {
        while(!st.hasMoreTokens())
            st = StringTokenizer(lines[++curLine])
        return st.nextToken()
    }
    fun nextInt() = next().toInt()
    fun nextLong() = next().toLong()
}

fun main() {
    val sc = Scanner()
    val buf = StringBuilder()

    val mp = Array(5) { Array(5) { -1 } }
    val dx = intArrayOf( 1, 0 )
    val dy = intArrayOf( 0, 1 )
    val v = ArrayList<Int>()

    fun dfs(x: Int, y: Int, s: Int = 0) {
        for((dx,dy) in dx zip dy)
            dfs(x+dx, y+dy, s)
    }
    dfs(0,0)

    val st = v.toSet().toIntArray()
    st.sort()
    println("${st.joinToString()}\n")

    for(i in 1..sc.nextInt()) {
        val k = sc.nextInt()
        val x = st.binarySearch(k)
        buf.append("$k\n")
    }

    print(buf)
}
