class Node{
	int info;
	Node left,right,next;
	Node(int data){
		info = data;
		left=right=next=null;
	}
}
class preNode{
	Node previous;
	preNode(){
		previous=null;
	}
}
class sucessor{
	//Method 1 reverse inorder  going to right most or end element first and then updating the changes
	void sucessor1(Node root, preNode pre){
		if(root==null){
			return;
		}
		sucessor1(root.right,pre);
		root.next = pre.previous;
		pre.previous = root;
		sucessor1(root.left,pre);
	}

	//Method 2 simple inorder going to the leftmost and making it previous and then as the traversal goes on moving the previous

	void sucessor2(Node root,preNode pre){
		if(root==null){
			return;
		}
		sucessor2(root.left,pre);
		if(pre.previous==null){
			pre.previous=root;
		}
		else{
			pre.previous.next =root;
			pre.previous = root; 
		}
		sucessor2(root.right,pre);

	}

	//Now next pointer points to predecessor of that node

	void predecessor(Node root,preNode pre){
		if(root==null){
			return;
		}
		predecessor(root.left,pre);
		root.next = pre.previous;
		pre.previous = root;
		predecessor(root.right,pre);
	}

	public static void main(String s[]){
        Node root = new Node(10);
        root.left = new Node(8);
        root.right = new Node(12);
        root.left.left = new Node(3);
 
 		sucessor ss = new sucessor();
      //calling first method
       ss.predecessor(root,new preNode());
 
        // Let us see the populated values
        Node ptr = root.right;
        while (ptr != null) {
            // -1 is printed if there is no successor
            int print = ptr.next != null ? ptr.next.info : -1;
            System.out.println("Next of " + ptr.info + " is: " + print);
            ptr = ptr.next;
        }
    }

}