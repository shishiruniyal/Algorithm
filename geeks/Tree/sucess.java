import java.util.*;
class Node{
	int data;
	Node left,right;
	Node(int value){
		data = value;
		left = right = null;
	}
}
class sucess{
	static Node previous = null;
	Node sucessor(Node root,int k){
			if(root==null){
				return null;
			}
			if(root.data==k){
				previous = root;
				return null;
			}
			else{
				if(previous==null){
					Node a=null,b=null;

					a = sucessor(root.left,k);
					if(a!=null){
						return a;
					}
					if(previous==null)
					b = sucessor(root.right,k);
					if(b!=null){
						return b;
					}
					if(previous!=null){
						if(root.left!=null&&root.left==previous){
							return root;
						}
						previous = root;
					}
				}
			}
			return null;
	}

	Node goodSucessor(Node root,int k,Node parent){
		if(root==null){
			return root;
		}
		if(root.data==k){
			return parent;
		}
		Node a = goodSucessor(root.left,k,root);
		if(a!=null){
			return a;
		}
		return goodSucessor(root.right,k,parent);
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		Node root = new Node(0);
		root.left = new Node(1);
		root.right = new Node(2);
		root.left.left = new Node(3);
		root.left.right = new Node(4);

		root.left.left.left = new Node(5);
		root.left.left.right = new Node(6);

		sucess s = new sucess();
		//Node n = s.sucessor(root,0);
		int item = sc.nextInt();
		Node n = s.goodSucessor(root,item,null);
		if(n!=null){
			System.out.println(n.data);
		}
		else{
			System.out.println("No sucessor");
		}

	}
}