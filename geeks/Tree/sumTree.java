class Node{
	int info;
	Node left;
	Node right;
	Node(int data){
		info = data;
		left = null;
		right = null;
	}
}
class sumTree{
public static boolean checkSum(Node root){
	if(root==null || (root.left==null&&root.right==null)){
		return true;
	}
	int lvalue=0,rvalue=0;
	boolean l = checkSum(root.left);
	boolean r = checkSum(root.right);

	if(root.left!=null){
		if(!isLeaf(root.left)){
			lvalue = 2*root.left.info;
		}
		else{
			lvalue = root.left.info;
		}
	}
	if(root.right!=null){
		if(!isLeaf(root.right)){
			rvalue = 2*root.right.info;
		}
		else{
			rvalue = root.right.info;
		}
	}

	return l&&r&&(root.info==lvalue+rvalue);
}
public static boolean isLeaf(Node temp){
	if(temp.left==null && temp.right==null){
		return true;
	}
	else{
		return false;
	}
}
public static void main(String[] s){
		Node root = new Node(26);
		root.left = new Node(10);
		root.right = new Node(3);
		root.left.left = new Node(4);
		root.left.right = new Node(6);
		root.right.left = new Node(4);
		
		if(checkSum(root)){
			System.out.println("Satisfies property");
		}
		else
			System.out.println("Not satifies");
	}

}