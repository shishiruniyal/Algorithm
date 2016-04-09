import java.util.Scanner;

class shishir{
	
	public static void main(String s[]){
	Scanner sc = new Scanner(System.in);
	int N,Js,Rs,Max,localMax,flag=0;
	N = sc.nextInt();
	Js = sc.nextInt();
	Max = 0;
	localMax = 0;
	while(N>0){
			Rs = sc.nextInt();
				if(Rs<=Js && flag < 2){
					localMax++;
				}
					else {
							flag++;
						}
			// else{
			// 	if(Max<localMax){
			// 	Max = localMax;
			// 	}
			// 	flag=1;
			// 	localMax =0;
			// 	}
		N--;
	}
	
	System.out.println(localMax);
	sc.close();
	}
}