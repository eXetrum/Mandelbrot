
import java.util.Formatter;


public class ComplexNumberP extends ComplexNumber{
    private double radius, theta;
    public ComplexNumberP() // calls super() 
    {
    super();
    radius=0;
    theta=0;
    }
    
  public ComplexNumberP(double r, double i) // calls super(r, i) 
    {
    super(r,i);
    update();
    }
  public ComplexNumberP(ComplexNumberP cn) // calls super(cn.r, cn.i) 
  {
    super(cn.getR(),cn.getI());
    update();
  }
  public ComplexNumberP(ComplexNumber cn) // calls super(cn) 
  {
      super(cn);
      update();
  }
  public void finalize() 
  {
      
  }
  @Override
  public void setR(double r) 
  {
      super.setR(r);
      update();
  }
  @Override
  public void setI(double i) 
  {
      super.setI(i);
      update();
  }
  public double getRadius() 
  {
   return radius;
  }
  public double getTheta() 
  {
      return theta;
  }
  public String toString() 
  {
      Formatter f = new Formatter();
      f.format("%.3f(cos(%.3f)+isin(%.3f))", radius, theta,theta);
      return f.toString();
  }
  ComplexNumberP mult(ComplexNumberP rhs) 
  {
      double r=radius*rhs.radius;
      double t=theta*rhs.theta;
      ComplexNumberP res=new ComplexNumberP(r*Math.cos(t),r*Math.sin(t));
      res.radius=r;
      res.theta=t;
      return res;
  }
  ComplexNumberP div(ComplexNumberP rhs) 
  {
    if(Math.abs(rhs.radius)>1e-6)
       {
           double r=radius/rhs.radius;
           double t=theta-rhs.theta;
           ComplexNumberP temp=new ComplexNumberP(r*Math.cos(t),r*Math.sin(t));
           temp.radius=r;
           temp.theta=t;
           return temp;
       }
    else
       return new ComplexNumberP(0,0);      
  }
  boolean equals (ComplexNumberP rhs)
  {
    if((Math.abs(rhs.radius-radius)<1e-6)&&(Math.abs(rhs.theta-theta)<1e-6))
        return true;
    else
        return false;

  }   
  private void update()
    {
    radius=Math.pow(getI()*getI()+getR()*getR(),0.5);
    if(Math.abs(getR())>1e-6)
        theta=Math.atan(getI()/getR());
    else
        theta=Math.PI;
    }

}
