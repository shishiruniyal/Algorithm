import java.util.LinkedList;
import java.util.Queue;

class Node{
	Node left,right;
	int value;

	Node(int val){
		value = val;
		left = null;
		right = null;
	}
}


class Hei{

	public int heightCalculate(Node root){
		int height = 0;
		Queue<Node> q = new LinkedList<Node>();
		q.add(root);
		int count = 0,outcount = 1;
		while(!q.isEmpty()){
			while(outcount!=0){
				Node temp = q.poll();
				if(temp.left!=null){
					q.add(temp.left);
					count++;
				}
				if(temp.right!=null){
					q.add(temp.right);
					count++;
				}
				outcount--;
			}
			height++;
			outcount = count;
			count=0;
		}

		return height-1;
	}


	public static void main(String s[]){
		Node root = new Node(1);
        root.left = new Node(2);
        root.right = new Node(3);
       	root.left.left = new Node(4);
        root.left.right = new Node(5);
        root.left.left.left = new Node(6);
        root.left.left.left.left = new Node(7);
        root.left.left.left.left.left = new Node(8);
		Hei H = new Hei();

		System.out.println("Height of the tree is "+ H.heightCalculate(root));
	}

}