class Node{
	int info;
	Node left,right;

	Node(int item){
		info = item;
		left = right=null;
	}
}
class sameTree{
	public static boolean check(Node tree1,Node tree2){
		if(tree1==null && tree2==null){
			return true;
		}
		else{
			if(tree1.info==tree2.info){
				boolean l,r;
				l=check(tree1.left,tree2.left);
				r=check(tree1.right,tree2.right);
				return l&&r;
			}
			return false;
		}
	}

	public static void main(String s[]){
		Node root1 = new Node(1);
    	Node root2 = new Node(1);
    	root1.left = new Node(2);
    	root1.right = new Node(3);
    	root1.left.left  = new Node(4);
    	root1.left.right = new Node(5); 
 
	    root2.left = new Node(21);
    	root2.right = new Node(3);
   		root2.left.left = new Node(4);
 	 	root2.left.right = new Node(5); 
 		
 		if(check(root1,root2)){
 			System.out.println("Identical trees");
 		}
 		else{
 			System.out.println("Different Trees");
 		}
	}
}