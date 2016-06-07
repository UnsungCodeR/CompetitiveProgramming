import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

    public static void main(String[] args) {
        Scanner stdin = new Scanner(System.in);
        int testno = stdin.nextInt();
       for (int testCaseIndex = 0; testCaseIndex < testno; testCaseIndex++) {
            int start = stdin.nextInt();
            int end = stdin.nextInt();
            int [] values = new int[10];
            
            for(int i = 0 ; i < 10; i++){
                values[i] = stdin.nextInt();
            }
            
            for(int seed = start; seed < end; seed++){
                Random rand = new Random(seed);
                boolean bad = false;
                for(int j = 0 ; j < 10 ; j++){
                    if(rand.nextInt(1000) != values[j]){
                        bad = true;
                        break;
                    }
                }
                
                if(!bad){
                    System.out.print(seed);
                    System.out.print(" ");
                   for(int j = 0 ; j < 10; j++){
                        System.out.print(rand.nextInt(1000));
                        System.out.print(" ");
                    }
                    System.out.println();
                }
            }
            
      
            
        }
    }
}