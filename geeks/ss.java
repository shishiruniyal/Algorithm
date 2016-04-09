import java.util.Scanner;

class ss{
	static String palin;
public static void main(String s[]){
	int[][] table;
	Scanner sc = new Scanner(System.in);
	String a,b;
	int f,se;
	a = sc.next();
	b = sc.next();

	f = lcsp(0,a.length()-1,a);
	

	se = lcsp(0,b.length()-1,b);
	
	if(f%2==0 && se%2==0){
		System.out.println(f+se);
	}
	else if((f%2==0 && se%2!=0)|| (f%2!=0 && se%2==0)){
		System.out.println(f+se);
	}
	else{
		
	}
}

public static int lcsp(int i,int j,String sr){
	if(i==j){
		palin = palin+sr.charAt(i);
		return 1;
	}
	if(sr.charAt(i)==sr.charAt(j) && j==i+1){
		palin = palin+sr.charAt(i)+sr.charAt(i);
		return 2;
	}
	else{
		if(sr.charAt(i)==sr.charAt(j)){
			return 2+lcsp(i+1,j-1,sr);
		}
		else{
			return max(lcsp(i+1,j,sr),lcsp(i,j-1,sr));
		}
	}
}
public static int max(int a,int b){
	return a>b?a:b;
} 
}