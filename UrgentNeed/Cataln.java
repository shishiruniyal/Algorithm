import java.io.*;
import java.util.Scanner;

class catalan{
	
	public static long combinatoric(int a, int b){
		long answer =1;
		b = a-b<b?a-b:b;
		while(b>0){
		answer = answer * a;
		answer = answer/b;
		b--;
		a--;
	}
	return answer;
	}

	
	public static void main(String s[]){
		Scanner sc = new Scanner(System.in);
		int N;
		long sol,fa;
		N = sc.nextInt();
		sol = combinatoric(2*N,N);
		System.out.println("Combi = "+sol);
		sol = sol/(N+1);
		System.out.println("No. of binary search tree is "+sol);
		sc.close();
	}
}