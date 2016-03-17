import java.util.Scanner;
import java.util.Queue;
import java.util.LinkedList;
class node{
int value;
node l;
node r;
node(int data){
	value = data;
	l = null;
	r = null;
}

}

class Main{

	// O(n) implementation using Queue
	public static void printLevelOrder(node root){
		Queue<node> q = new LinkedList<node>();
		node temp;
		temp = root;

		while(temp!=null){
			System.out.print(temp.value+" ");
			if(temp.l!=null){
				q.add(temp.l);}
		if(temp.r!=null){
			q.add(temp.r);}
		temp = q.poll();}
	}

	//finding out height of the tree
	public static int height(node root){
		if(root==null){
			return -1;
		}
	int lheight = 1+height(root.l);
	int rheight = 1+height(root.r);

	return lheight>rheight?lheight:rheight;
	}
	
	public static void main(String s[]){
		node root = new node(1);
		node l,r;
		l = new node(2);
		root.l = l;
		r = new node(3);
		root.r = r;
		l = new node(4);
		r = new node(5);
		root.l.l = l;
		root.l.r = r;
		l = new node(6);
		r = new node(7);
		root.r.l = l;
		root.r.r = r;

		printLevelOrder(root);
		System.out.println("Height of the tree is "+height(root));
	}
}
