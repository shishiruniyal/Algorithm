import java.util.Scanner;

class Max{


	public static void main(String s[]){
		int test;
		long k;
		int n,index;
		long a[];
		long b[];
		long max = 0,answer = 0,diff;
		Scanner sc = new Scanner(System.in);

		test = sc.nextInt();
		while(test>0){
			max = 0;
			index = 0;
			diff = 0;
			answer = 0;

			n = sc.nextInt();
			k = sc.nextLong();
			a = new long[n];
			b = new long[n];

			// taking input array a
			for(int i=0;i<n;i++){
				a[i] = sc.nextLong();
			}

			// take array b as input
			for(int i=0;i<n;i++){
				b[i] = sc.nextLong();

				if(Math.abs(b[i])>max){
					max = Math.abs(b[i]);
					index = i;
				}
			}
			//System.out.println("Max is "+max+" index is "+index);

			if(b[index]<0){
				a[index] = a[index]-k;
			}
			
			else{
			a[index] = a[index]+k;
				 
			}
				
			for(int i=0; i<n;i++){
				answer = answer + a[i]*b[i];
			}


			System.out.println(answer);

			test--;
		}
	}
}