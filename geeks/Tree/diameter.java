import java.util.Stack;

class Node{
	Node left,right;
	int value;
	int height;

	Node(int item){
		value = item;
		left = null;
		right = null;
		height = 0;
	}
}

class diameter{


	public static int max(int a,int b,int c){
		return (a>b?(c>a?c:a):(c>b?c:b));
	}

	public int height(Node root){
		if(root==null){
			return 0;
		}
		else{
			int lh = 1+height(root.left);
			int rh = 1+height(root.right);
			root.height = lh>rh?lh:rh;
			return (root.height);
		}
	}

	public int diameter1(Node root){
		if(root==null){
			return 0;
		}
		else{
			if(root.left!=null && root.right!=null)
				return max(root.left.height+root.right.height+1,diameter1(root.left),diameter1(root.right));
			else if(root.left==null && root.right!=null){
				return max(root.right.height+1,diameter1(root.left),diameter1(root.right));
			}
			else{
				return max(1,diameter1(root.left),diameter1(root.right));
			}
		}
	}
}


class Main{
	public static void main(String s[]){
		Node root = new Node(1);
			Node n1 = new Node(2);
			Node n2 = new Node(3);
			Node n3 = new Node(4);
			Node n4 = new Node(5);
			Node n5 = new Node(6);
			Node n6 = new Node(7);
			Node n7 = new Node(8);
			Node n8 = new Node(9);
			Node n9 = new Node(10);

			root.left = n1;
			root.right = n2;

			n1.left = n3;
			n1.right = n4;

			n4.right = n5;
			n5.right = n9;

			n3.left = n8;
			n8.left = n7;
			n7.left = n6;
		diameter d = new diameter();
		d.height(root);
		System.out.println("Diameter is "+d.diameter1(root));

	}
}