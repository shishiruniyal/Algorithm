import java.io.*;
import java.util.*;
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

    public void PrintIterative(Node root,int k){
        Stack<Node> path = new Stack<Node>();
        path.add(root);
        root = root.left;

        while(!path.empty()){
        	while(root!=null&&root.value!=k){
        		path.push(root);
        		root = root.left;
        	}
        	if(root!=null&&root.value==k){
        		break;
        	}
        	if((path.peek()).right==null){
        		root = path.pop();

        		while(!path.empty()&&((path.peek()).right==root)){
        			root = path.pop();
        		}
        	}
        	if(!path.empty())
        	root = (path.peek()).right;
        }
        System.out.println("Iterative path");
        while(!path.empty()){
        	System.out.print(" "+(path.pop()).value);
        }
    
    }

	public static void main(String s[]){

		Node root = new Node(1);
		
		root.right = new Node(3);
		
		root.right.right = new Node(7);
		root.right.right.right = new Node(10);
		root.right.right.right.right = new Node(11);
		root.right.right.right.right.right = new Node(12);
	
		ancestor a = new ancestor();

		a.PrintAncestor(root,13);
		System.out.println();

		a.PrintIterative(root,12);
		System.out.println();

	}
}
