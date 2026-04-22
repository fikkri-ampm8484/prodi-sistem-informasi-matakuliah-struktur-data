import java.util.Stack;

public class ParenthesesChecker {

    public static boolean isBalanced(String expr) {
        Stack<Character> stack = new Stack<>();

        for (char c : expr.toCharArray()) {
            if (c == '(' || c == '[' || c == '{') {
                stack.push(c);
            }
            else if (c == ')' || c == ']' || c == '}') {
                if (stack.isEmpty()) {
                    return false;
                }
                char top = stack.pop();
                if (!isMatchingPair(top, c)) {
                    return false;
                }
            }
        }
        return stack.isEmpty();
    }

    static boolean isMatchingPair(char open, char close) {
        return (open == '(' && close == ')')
            || (open == '[' && close == ']')
            || (open == '{' && close == '}');
    }

    public static void main(String[] args) {
        String input1 = "{[()]}";
        String input2 = "{[(])}";

        System.out.println("Input: " + input1 + " -> Balanced? " + isBalanced(input1));
        System.out.println("Input: " + input2 + " -> Balanced? " + isBalanced(input2));
    }
}