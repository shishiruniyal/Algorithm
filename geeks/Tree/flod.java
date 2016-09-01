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
class fold{

	public static boolean checkFoldable(Node root1,Node root2){
		if(root1==null && root2==null){
			return true;
		}
		
		if(root1!=null && root2!=null){
			boolean l = checkFoldable(root1.left,root2.right);
			boolean r = checkFoldable(root1.right,root2.left);
			return l&&r;
		}
		else{
			return false;
		}
	}

	public static void main(String[] s){
		Node root = new Node(10);
		root.left = new Node(7);
		root.right = new Node(15);
		root.left.left = new Node(9);
		root.left.right = new Node(10);
		root.right.left = new Node(12);
		
		if(checkFoldable(root.left,root.right)){
			System.out.println("Provided tree is foldable");
		}
		else
			System.out.println("Not foldable");
	}



}