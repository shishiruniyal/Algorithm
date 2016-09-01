import java.util.Stack;
class Node{
	int info;
	Node left,right;
	Node(int data){
		info = data;
		left = right = null;
	}
}
class spiral{
	int height(Node root){
		if(root==null){
			return -1;
		}
		else{
			int lh = height(root.left);
			int rh = height(root.right);
			if(lh>rh){
			return 1+lh;
			}
			else{
			return 1+rh;
			}
		}
	}

	void printSpiral(Node root){
		for(int i=0;i<=height(root);i++){
			if(i%2==0)
			printLevel(root,i,true);
			else
				printLevel(root,i,false);
		}
		System.out.println();
	}

	void printLevel(Node root,int i,boolean even){
		if(root==null){
			return;
		}
		if(i==0){
			System.out.print(" "+root.info);
			return;
		}
		if(even){
			printLevel(root.right,i-1,even);
			printLevel(root.left,i-1,even);
		}
		else{
			printLevel(root.left,i-1,even);
			printLevel(root.right,i-1,even);
		}
	}

	public static void main(String s[]){
		Node root = new Node(1);
		root.left = new Node(2);
		root.right = new Node(3);
		root.left.left = new Node(7);
		root.left.right = new Node(6);
		root.right.left = new Node(5);
		root.right.right = new Node(4);

		root.left.left.left = new Node(8);
		root.left.left.right = new Node(9);
		root.left.right.right = new Node(10);
		root.right.left.left = new Node(11);
		root.right.right.right = new Node(12);

		spiral sp = new spiral();
		sp.printSpiral(root);
		System.out.println("Now iterative version");
		sp.printSpiralIterative(root);
		System.out.println();
	}

	void printSpiralIterative(Node root){
		Stack<Node> s1 = new Stack<Node>(); // right to left 
		Stack<Node> s2 = new Stack<Node>();	// left to right

		s1.push(root);
		while(!s1.empty() || !s2.empty()){
			while(!s1.empty()){
				Node temp = s1.pop();
				System.out.print(" "+temp.info);
				if(temp.right!=null){
					s2.push(temp.right);
				}
				if(temp.left!=null){
					s2.push(temp.left);
				}
			}
			while(!s2.empty()){
				Node temp = s2.pop();
				System.out.print(" "+temp.info);
				if(temp.left!=null){
					s1.push(temp.left);
				}
				if(temp.right!=null){
					s1.push(temp.right);
				}
			}
		}
	}
}