import java.util.Scanner;

class palindrome{
	public static void main(String s[]){
		Scanner sc = new Scanner(System.in);
		int test;
		String a,b;
		boolean check[] = new boolean[26];

		test = sc.nextInt();

		while(test>0){
			boolean flag=false;
		a = sc.next();
		b = sc.next();
		for(int i=0;i<26;i++){
			check[i] = false;
		}

		for(int i=0;i<a.length();i++){
			check[a.charAt(i)-'a'] = true;
		}
		for(int j=0;j<b.length();j++){
			if(check[b.charAt(j)-'a']==true){
				System.out.println("Yes");
				flag = true;
				break;
			}
		}
		if(!flag){
			System.out.println("No");
		}
		test--;
		}
		sc.close();
	}
}