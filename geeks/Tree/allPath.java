class Node{
	Node left,right;
	int info;
	Node(int item){
		left=right=null;
		info = item;
	}
}
class allPath{
	public static void printPath(String path,Node root){
		if(root.left==null && root.right==null){
			System.out.println(path+root.info);
			return;
		}
		path = path+root.info;
		printPath(path,root.left);
		printPath(path,root.right);
		return;
	}

	public static void main(String[] s){
		Node root = new Node(1);
		root.left = new Node(2);
		root.right = new Node(3);
		root.left.left = new Node(4);
		root.left.right = new Node(5);
		printPath("",root);
	}
}