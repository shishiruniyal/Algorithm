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

class ancestor{
	static boolean parent = false;
	public void PrintAncestor(Node root,int k){
		if(root==null){
			return;
		}
		if(k==root.value){
			parent = true;
			return;
		}
			if(!parent){
				PrintAncestor(root.left,k);
			}
			if(!parent){
				PrintAncestor(root.right,k);
			}
			if(parent){
			System.out.print(" "+root.value);
			return;
		}
	}

	public static void main(String s[]){

		Node root = new Node(1);
		root.left = new Node(2);
		root.right = new Node(3);
		root.left.left = new Node(4);
		root.left.right = new Node(5);
		root.left.left.left = new Node(7);
		ancestor a = new ancestor();

		a.PrintAncestor(root,7);
		System.out.println();

	}
}