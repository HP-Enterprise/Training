import java.awt.*;
import java.awt.event.AdjustmentEvent;
import java.awt.event.AdjustmentListener;
import java.awt.event.MouseWheelEvent;
import java.awt.event.MouseWheelListener;
import java.util.Date;
import java.util.Vector;

import javax.swing.*;

public class ScrollBarDemo {

    public static void main(String[] args) {
        DrawFrame frame = new DrawFrame();
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setVisible(true);
    }

}

class DrawFrame extends JFrame {
    private static String txt=buildTxt(50);
    public DrawFrame() {
        setTitle("ScrollBarDemo");
        setSize(DEFAULT_WIDTH, DEFAULT_HEIGHT);
        // �� panel �ӵ� frame
        DrawPanel panel = new DrawPanel();
        Container contentPane = getContentPane();

        Scrollbar scrollBar = new Scrollbar();

        scrollBar.setOrientation(Scrollbar.VERTICAL);
        contentPane.add(panel, BorderLayout.CENTER);

        scrollBar.addAdjustmentListener(new AdjustmentListener() {
            @Override
            public void adjustmentValueChanged(AdjustmentEvent e) {
                panel.repaint(scrollBar.getValue());
            }
        });

        this.addMouseWheelListener(new MouseWheelListener() {
            @Override
            public void mouseWheelMoved(MouseWheelEvent e) {
                scrollBar.setValue(scrollBar.getValue() + e.getWheelRotation());
                panel.repaint(scrollBar.getValue());
            }
        });

        contentPane.add(scrollBar, BorderLayout.EAST);
    }

    public static final int DEFAULT_WIDTH = 800;
    public static final int DEFAULT_HEIGHT = 600;


    class DrawPanel extends JPanel {
        private int scrollBarValue=0;

        public void paintComponent(Graphics g,double leftX,  double topY ) {
            super.paintComponent(g);

            g.setFont(new Font("", Font.ROMAN_BASELINE, 16));

            String[] str=format(txt,this.getWidth(),g);//����п�=������-6
            drawTxtArray(str,g,0,(int) topY + 10);//��ʼ����

            g.drawString("�������һ���ı� ��ǰ�����и�:" + g.getFontMetrics().getHeight()+"  ������:"+this.getWidth(), 0, this.getHeight()-5 );
        }

        // �ַ����и�,ʵ���ַ����Զ�����

        /**
         * �и��ַ���Ϊ���飬�����ַ��ڵ�ǰ����Ķ�Ӧ����Լ����������п������
         * @param text �ַ���
         * @param maxWidth ����� ���ݵ�ǰ�����ȼ���
         * @param g Graphics
         * @return
         */
        public  String[] format(String text, int maxWidth, Graphics g) {
            String[] result = null;
            Vector tempR = new Vector();
            int lines = 0;
            int len = text.length();
            int index0 = 0;
            int index1 = 0;
            boolean wrap;
            while (true) {
                int widthes = 0;
                for (index0 = index1; index1 < len; index1++) {
                    widthes = g.getFontMetrics().charWidth(text.charAt(index1)) + widthes;
                    if (widthes > maxWidth) {
                        break;
                    }
                }
                lines++;
                tempR.addElement(text.substring(index0, index1));
                if (index1 >= len) {
                    break;
                }
            }
            result = new String[lines];
            tempR.copyInto(result);
            return result;
        }

        /**
         * д�ַ������鵽ָ����ʼ����
         * @param texts �ı�����
         * @param g Graphics
         * @param x ��ʼ����x
         * @param y ��ʼ����y
         */
        public void drawTxtArray(String[] texts,Graphics g,int x,int y){
            for(int i=0;i<texts.length;i++){
                if(y+g.getFontMetrics().getHeight()*i<=this.getHeight()-g.getFontMetrics().getHeight()){
                    //ȷ���ı�������Ƶ����һ�еı�������
                    g.drawString(texts[i], 0, y + g.getFontMetrics().getHeight()*i);
                }

            }
        }

        /**
         * �Զ������ػ淽��
         * @param g Graphics
         */
        public void paint(Graphics g) {

            System.out.println(new Date().toLocaleString() + " �ػ�..." + this.getWidth() + ":" + this.getHeight()+" value:"+scrollBarValue);
            paintComponent(g, 0, 10 - scrollBarValue * 5 );
        }

        /**
         * ���ص�repaint���� ʹ��scrollBarValue���ƻ�������
         * @param value scrollBarValue
         */
        public void repaint(int value) {

            scrollBarValue=value;
            super.repaint();
        }

    }

    /**
     *  �����ı�
     * @param lineLength �ı���
     * @return
     */
    public static String buildTxt(int lineLength){
        StringBuilder sb=new StringBuilder();
        for(int i=0;i < lineLength; i++) {
            //sb.append(new Date().getTime()).append("-").append(i+"t");
            for(int j=65;j<91;j++){
                sb.append((char)j);
            }
        }
        return sb.toString();
    }
}

