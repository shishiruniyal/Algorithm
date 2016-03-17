import java.util.Scanner;

class chefspl{

public static boolean evenCheck(StringBuilder s){
	int length = s.length();
	int i=0;
	while(i<(length/2) && s.charAt(i)==s.charAt(length/2+i)){
		i++;
	}
	if(i==length/2){
		return true;
	}
		return false;
}

public static void main(String[] args){
int test;
Scanner sc;
StringBuilder input;
int length;
boolean check;
int oddCount,index;
int[] alpha = new int[26];

sc = new Scanner(System.in);
test = sc.nextInt();

while(test>0){
	oddCount=0;
	check=true;
	index = 0;
	input = new StringBuilder(sc.next());
	//System.out.println(input);
	length = input.length();
	for(int i=0;i<26;i++){
		alpha[i]=0;
	}
	if(length!=1)
	{
	if(length%2==0){
		check = evenCheck(input);
	}
	else{
		for(int i=0;i<length;i++){
			alpha[input.charAt(i)-'a']+=1;
		}
		for(int i=0;i<26;i++){
			if(alpha[i]%2!=0){
				oddCount++;
				index = i;
			}
			if(oddCount>1){
				check = false;
				break;
			}
		}
		if(check==true && oddCount==1){
			input.deleteCharAt(index);
			check = evenCheck(input);
		}
		
	}
}
else{
	check = false;
}
	if(check){
			System.out.println("YES");
		}
		else{
			System.out.println("NO");
		}
	test--;
}
}

}






