class Node{
	Node left,right;
	int value;

	Node(int val){
		value = val;
		left = null;
		right = null;
	}
}

class Morris{

	public void inorder(Node root){
		Node current = root;
		Node pred;

		while(current!=null){
			if(current.left!=null){
				pred = current.left;
				while(pred.right!=null && pred.right!=current){
					pred = pred.right;
				}
				if(pred.right==current){
					pred.right = null;
					System.out.print(current.value+" ");
					current = current.right;
				}
				else{
					pred.right = current;
					current = current.left;
				}
			}

			else{
				System.out.print(current.value+" ");
				current = current.right;
			}
		}
	}


	public static void main(String s[]){
		Node root = new Node(1);
        root.left = new Node(2);
        root.right = new Node(3);
       	root.left.left = new Node(4);
        root.left.right = new Node(5);
		Morris m = new Morris();

		m.inorder(root);
	}

}