import java.util.Scanner;

class chefspl{

	public boolean check(String input){

		int count,length,i,j;boolean flag;

		length = input.length();
		flag = true;

		if(length==1){
			return false;
		}
		if(length%2==0){
			i = 0; j = length/2;
				while(i<length/2){ 
					if(input.charAt(i) == input.charAt(j)){
					i++;
					j++;
				}
				else{
					return false;
				}
			}

		}


		else{
			
			//case 1 on the left
			i=0;j=length/2+1;
			count=0;
			flag = true;
			while(i<=length/2 && j<length){
				if(input.charAt(i)==input.charAt(j)){
					i++;
					j++;
				}
				else if(count==0 && input.charAt(i+1)==input.charAt(j)){
					count++;
					i++;
				}
				else{
					flag = false;
					break;
				}
			}
			//case 2 on the right

			if(flag==false){
				i=0;j=length/2;
				count=0;
				flag=true;

				while(i<length/2 && j<length){
				if(input.charAt(i)==input.charAt(j)){
					i++;
					j++;
				}
				else if(count==0 && input.charAt(i)==input.charAt(j+1)){
					count++;
					j++;
				}
				else{
					flag = false;
					break;
				}
			}

			}
		}		
			return flag;

		}




	public static void main(String s[]){
		Scanner sc = new Scanner(System.in);
		int test;
		String input;
		boolean finnal;

		test = sc.nextInt();
		chefspl c = new chefspl();
		while(test>0){

			input = sc.next();
			finnal = c.check(input);
			if(finnal){
				System.out.println("YES");
			}
			else{
				System.out.println("NO");
			}
			test--;
		}
	}
}