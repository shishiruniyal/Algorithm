class Node{
	int info;
	Node left,right;

	Node(int item){
		info = item;
		left = right=null;
	}
}

class pathSum{
	public boolean check(Node root, int value){
		if(root==null){
			if(value==0){
				return true;
			}
			else{
				return false;
			}
		}
		return check(root.left,value-root.info) || check(root.right,value-root.info);
	}

	public static void main(String s[]){
		int sum = 14;
        pathSum p = new pathSum();
        Node root = new Node(10);
        root.left = new Node(8);
        root.right = new Node(2);
        root.left.left = new Node(3);
        root.left.right = new Node(5);
        root.right.left = new Node(2);
 
        if (p.check(root, sum)) {
            System.out.println("There is a root to leaf path with sum " + sum);
        } else {
            System.out.println("There is no root to leaf path with sum " + sum);
        }
	}
}