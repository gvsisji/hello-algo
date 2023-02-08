/**
 * File: PrintUtil
 * Created Time: 2023-01-23
 * Author: Jefferson (JeffersonHuang77@gmail.com)
 */
import 'dart:io';

import 'list_node.dart';
import 'tree_node.dart';

class Trunk {
  Trunk? prev;
  String str;

  Trunk(this.prev, this.str);
}

class PrintUtil {
  static void printLinkedList(ListNode? head) {
    List<String> list = [];

    while (head != null) {
      list.add('${head.val}');
      head = head.next;
    }

    print(list.join(' -> '));
  }
  /*
   * Print a binary tree
   * @param root
   * @param prev
   * @param isLeft
   */

  static void printTree(TreeNode? root,
      [Trunk? prev = null, bool isLeft = false]) {
    if (root == null) {
      return;
    }

    String prev_str = '    ';
    Trunk trunk = Trunk(prev, prev_str);

    printTree(root.right, trunk, true);

    if (prev == null) {
      trunk.str = '---';
    } else if (isLeft) {
      trunk.str = '/---';
      prev_str = '   |';
    } else {
      trunk.str = '\\---';
      prev.str = prev_str;
    }
    showTrunks(trunk);
    print(' ${root.val}');

    if (prev != null) {
      prev.str = prev_str;
    }
    trunk.str = '   |';

    printTree(root.left, trunk, false);
  }

  static void showTrunks(Trunk? p) {
    if (p == null) {
      return;
    }

    showTrunks(p.prev);
    stdout.write(p.str);
  }
}
