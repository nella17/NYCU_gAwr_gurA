import java.io.*;
import java.util.*;
import java.math.*;

public class main {
    Scanner sc;
    PrintWriter out;

    void run() throws Exception {
        sc = new Scanner(System.in);
        out = new PrintWriter(System.out);

        int n = sc.nextInt();
        sc.nextLine();
        String s = sc.nextLine();
        ArrayList<Character> v = new ArrayList<Character>();
        BigInteger c = BigInteger.valueOf(v.get(n));
        c.isProbablePrime(10); // 1 - 0.5 ^ 10
        c.nextProbablePrime();
        out.println(c);

        out.flush();
    }
    
    public static void main(String[] args) throws Exception {
        new main().run();
    }
}
