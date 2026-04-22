import java.util.Stack;

public class InfixConverter {

    public static String infixToPostfix(String expr) {
        StringBuilder output = new StringBuilder();
        Stack<Character> stack = new Stack<>();
        for (char c : expr.toCharArray()) {
            if (Character.isLetterOrDigit(c)) {
                output.append(c);
            }
            else if (c == '(') {
                stack.push(c);
            }
            else if (c == ')') {
                while (!stack.isEmpty() && stack.peek() != '(') {
                    output.append(stack.pop());
                }
                if (!stack.isEmpty()) {
                    stack.pop();
                }
            }
            else if (isOperator(c)) {
                while (!stack.isEmpty()
                    && stack.peek() != '('
                    && precedence(stack.peek()) >= precedence(c)) {
                    output.append(stack.pop());
                }
                stack.push(c);
            }
        }
        while (!stack.isEmpty()) {
            output.append(stack.pop());
        }
        return output.toString();
    }

    static boolean isOperator(char c) {
        return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
    }

    static int precedence(char op) {
        switch (op) {
            case '+': case '-': return 1;
            case '*': case '/': return 2;
            case '^': return 3;
            default: return 0;
        }
    }

    public static void main(String[] args) {
        String input = "a+b*(c^d-e)";
        System.out.println("Infix: " + input);
        System.out.println("Postfix: " + infixToPostfix(input));
    }
}