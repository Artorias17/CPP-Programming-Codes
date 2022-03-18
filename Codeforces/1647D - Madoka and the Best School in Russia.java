import java.io.*;

public class Solve {
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out));
        int t =  Integer.parseInt(reader.readLine());
        int x, d, y, combinations;

        while(t-- > 0){
            String[] temp = reader.readLine().split(" ");
            x = Integer.parseInt(temp[0]);
            d = Integer.parseInt(temp[1]);
            y=0;
            while(x % d == 0){
                x/=d;
                y++;
            }
            combinations = x*d % (d*d) !=0 ? 1:0;
            switch(y){
                case 0:
                case 1:
                    writer.write("No\n");
                    break;
                case 2:
                    if(combinations + check(x, d, d) == 2) writer.write("Yes\n");
                    else writer.write("No\n");
                    break;
                case 3:
                    if(combinations + check(x, d, d) + check(d, d, x*d) >= 2) writer.write("Yes\n");
                    else writer.write("No\n");
                    break;
                default:
                    if(combinations + check(x, d, d) + check(d, d, d) + check(d, d, x*d) >= 2) writer.write("Yes\n");
                    else writer.write("No\n");
            }
        }
        writer.flush();
    }

    public static int check(int target, int d, int other){
        for(int i=2; i<=(int)Math.sqrt(target); i++){
            if(target % i == 0 && ((d*i % (d*d) != 0 && other*(target/i) % (d*d) != 0) || (other*i % (d*d) != 0 && d*(target/i) % (d*d) != 0))){
                return 1;
            }
        }
        return 0;
    }
}

/*
 * Logic
 * Given x and d...
 * x can be decomposed to (d^y) * b where b is not divisible by b.
 * According to question...
 * A beautiful number is one that is a multiple of only one d.
 * Or more precisely, a beautiful number is not a multiple of d^2.
 * And, we are required to say "YES" or "NO" based on whether at least 2
 * combinations of product of one or several beautiful number(s) can be formed to give x.
 *
 * So, at least 2 ds are needed.
 *
 * If number of d is 2. Then the combinations are
 * d*(d*b)
 * (d*g)*(d*h) where g and h are factors of b.
 *
 *
 * If number of d is 3. Then the combinations are
 * d*(d*b)
 * (d*g)*(d*h) where g and h are factors of b
 * (d*i)*(d*b*j) where i and j are factors of d
 *
 *
 * If number of d is 4 or more. Then the combinations are
 * d*(d*b)*d...
 * (d*g)*(d*h)*d... where g and h are factors of b
 * (d*i)*(d*j)*d... where i and j are factors of d
 * (d*i)*(d*b*j)*d... where i and j are factors of d
 *
 * In all of these factor combinations of x,
 * the combination where none of the factors are multiple of d^2
 * is considered.
 * And, we need a minimum of 2 such combinations.
 */
