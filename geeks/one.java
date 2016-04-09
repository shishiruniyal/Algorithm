import java.io.*;
import java.util.Scanner;

class one{

	public static void main(String s[]){

		boolean a[];
		int i,j;
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		a = new boolean[n];
		for(i=0;i<n;i++){
			a[i]=false;
		}
		for(i=0;i<n;i++){
			j = sc.nextInt();
			if(j!=0){
				a[j-1]=true;
			}
		}
		for(i=0;i<n;i++){
			if(!a[i]){
				System.out.print((i+1)+" ");
			}
		}
	}
}