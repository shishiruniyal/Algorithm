import java.io.*;
import java.util.Scanner;

public class kmp
{
	private int dfa[][];
	private String pattern;
	private String text;
	kmp(int len,String pat,String tex){
		dfa = new int[26][len];
		pattern = pat;
		text = tex;
	}

//making dfa

	public void preprocess(){
		int M = dfa[0].length;
		dfa[pattern.charAt(0)-'a'][0]= 1;
		for(int j=1,x=0; j<M;j++){
			for(int c = 0;c<25;c++){
				dfa[c][j] = dfa[c][x];
			}
			dfa[pattern.charAt(j)-'a'][j] = j+1;
			x = dfa[pattern.charAt(j)-'a'][x];  
		}
	}

//matching with pattern of text
	public void Matching(){
		int N = text.length();
		int M = dfa[0].length;
		this.preprocess();
		for(int i=0,j=0;i<N;i++){
			if(text.charAt(i)==' ')continue;
			j=dfa[text.charAt(i)-'a'][j];
			if(j==M){
				System.out.println("pattern found at position "+(i-M+1));
				j=0;
			}
		}
	}


	public static void main(String args[]){
		String text;
		String pattern;
		int len;
		Scanner sc = new Scanner(System.in);
		
		System.out.println("Enter the text string");
		text = sc.nextLine();
		System.out.println("Enter the pattern");
		pattern = sc.nextLine();
		len = pattern.length();
		kmp k = new kmp(len,pattern,text);
		k.Matching();
	}
}