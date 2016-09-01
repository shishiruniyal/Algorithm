import java.util.*;

class Node{
	int data;
	Node left,right;

	Node(int value){
		data = value;
		left = right = null;

	}
}

class leftView{

	int FindHeight(Node root){
		if(root==null){
			return -1;
		}

		int lh = FindHeight(root.left)+1;
		int rh = FindHeight(root.right)+1;
		return lh>rh?lh:rh;

	}

	static int height;

	void PrintL(Node root1,Node root2){
		if(root1==null){
			return;
		}
		System.out.print(root1.data+" ");
		height--;
		PrintL(root1.left,root2.right);

		if(height>=0){
			if(root2.left!=null){
				PrintL(root2.left,root2.right);
			}
			else{
				PrintL(root2.right,root2.right);
			}
		}
	}

	int maxx(Node root){
	
		if(root==null){
			return Integer.MIN_VALUE;
		}

		int l = maxx(root.left);
		int r = maxx(root.right);
		if(root.data>l){
			l = root.data;
		}
		if(r>l){
			l = r;
		}
		return l;
	}

	public static void main(String[] args) {
		Node root = new Node(1);
		root.left = new Node(2);
		root.left.left = new Node(3);
		root.right = new Node(3);
		root.right.right = new Node(4);
		root.right.right.right = new Node(50);
		root.right.right.right.left = new Node(9);
		root.right.right.right.left.left = new Node(10);
		root.right.right.right.right = new Node(6);
		root.right.right.right.right.right = new Node(7);
		root.right.right.right.right.right.right = new Node(8);



		leftView l =new leftView();

		// height = l.FindHeight(root);

		// l.PrintL(root,root);

		System.out.println("Maximum value is "+l.maxx(root));
	}

}