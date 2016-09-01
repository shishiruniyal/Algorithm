import java.util.*;
class Node{
	int data;
	int count;
	Node left,right;
	Node(int value){
	data = value;
	count = 0;
	left=right=null;
	}
}
class isoMorphism{
	static void Inorder(Node root){
		if(root==null){
			return;
		}
		Inorder(root.left);
		System.out.println("data  = "+root.data+" count = "+root.count);
		Inorder(root.right);
	}
	static int count = 0;
	//	checking weather both the trees are isomorphic or not
	static boolean Iso(Node root1,Node root2){
		count++;
		if(root1==null&&root2==null){
			return true;
		}
		if(root1==null||root2==null){
			return false;
		}
		if(root1.data!=root2.data){
			root1.count = root1.count+1;
			root2.count = root2.count+1;
			return false;
		}
		return ((Iso(root1.left,root2.left)&&Iso(root1.right,root2.right))||(Iso(root1.left,root2.right)&&Iso(root1.right,root2.left)));
	}

	static void NextRight(Node root,int key){
		if(root==null){
			return;
		}
		Queue<Node> q = new LinkedList<Node>();
		boolean flag = false;
		q.add(root);
		Node temp;
		int inCount=0;
		int outCount =1;
		while(!q.isEmpty()&&!flag){
			inCount = outCount;
			outCount = 0;

			while(inCount>0){
				temp = q.poll();
				if(temp.data==key){
					flag = true;
					if(inCount>1){
						System.out.println(" Next Right is "+q.peek().data);
					}
					else{
						System.out.println("Next Right is NULL");
					}
					break;
				}
				if(temp.left!=null){
					q.add(temp.left);
					outCount++;
				}
				if(temp.right!=null){
					q.add(temp.right);
					outCount++;
				}
				inCount--;
			}
		}
	}
	public static void main(String[] args) {
		Node root1 = new Node(1);
		root1.left = new Node(2);
		root1.right = new Node(3);

		root1.left.left = new Node(4);
		root1.left.right = new Node(5);

		root1.left.right.left = new Node(6);
		root1.left.right.right = new Node(7);

		root1.right.left = new Node(8);


		// Node root2 = new Node(1);

		// root2.left = new Node(1);
		// root2.right = new Node(1);

		// //root1.left.left = new Node(4);
		// root2.left.right = new Node(1);



		// root2.right.left = new Node(1);

		// root2.right.right = new Node(1);
		// root2.right.right.left  = new Node(1);

		// root2.right.right.right = new Node(1);

		// if(Iso(root1,root2)){
		// 	System.out.println("Yes Isomorphic"+count);
		// }
		// else{
		// 	System.out.println("Not Isomorphic"+count);
		// }
		// Inorder(root1);
		//Inorder(root2);
		Scanner sc = new Scanner(System.in);
		int key = sc.nextInt();
		NextRight(root1,key);

	}
}