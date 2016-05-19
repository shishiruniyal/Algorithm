import java.io.*;

class Node{
	int value;
	Node left,right;

	Node(int data){
		value = data;
		left = null;
		right = null;
	}
}

class DistanceK{

	public void PrintK(Node root,int k){
		if(root==null){
			return;
		}
		if(k==0){
			System.out.print(" "+root.value);return;
		}
		else{
			PrintK(root.left,k-1);
			PrintK(root.right,k-1);
		}
	}

	public static void main(String s[]){

		Node root = new Node(1);
		root.left = new Node(2);
		root.right = new Node(3);
		root.right.left = new Node(8);
		root.left.left = new Node(4);
		root.left.right = new Node(5);

		DistanceK d = new DistanceK();

		d.PrintK(root,0);
		System.out.println();

	}
}