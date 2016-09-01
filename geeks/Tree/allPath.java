import java.util.LinkedList;
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

	public static void printPath2(LinkedList<Integer> li,Node root){
		if(root==null){
			return;
		}
		li.add(root.info);
		if(root.left==null &&root.right==null){
			
			for(int i:li)
				System.out.print(" "+i);
			System.out.println();
		}
		printPath2(li,root.left);
		printPath2(li,root.right);
		li.removeLast();   //removing last element is essential 
	}

	public static void main(String[] s){
		Node root = new Node(1);
		root.left = new Node(2);
		root.right = new Node(3);
		root.left.left = new Node(4);
		root.left.right = new Node(5);
		LinkedList<Integer> li = new LinkedList<Integer>();
		printPath2(li,root);
		System.out.println("Second one");
		printPath("",root);
	}
}