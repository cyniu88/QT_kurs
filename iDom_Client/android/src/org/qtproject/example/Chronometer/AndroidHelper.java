//
//AndroidHelper.java
//
package org.qtproject.example.Chronometer;

import android.content.Context;
import android.os.Vibrator;
import android.app.Activity;
import android.os.Bundle;
import android.widget.Toast;


public class AndroidHelper extends org.qtproject.qt5.android.bindings.QtActivity
{

public static Vibrator m_vibrator;
public static AndroidHelper m_istance;

public AndroidHelper()
{
m_istance = this;
}

public static void vibrate(int x)
{
if (m_vibrator == null)
{
if (m_istance != null)
{
m_vibrator = (Vibrator) m_istance.getSystemService(Context.VIBRATOR_SERVICE);
m_vibrator.vibrate(x);
}

   }
   else m_vibrator.vibrate(x);

}





public  void makeToast(int n)
{
    Context context = getApplicationContext();
    CharSequence text = "Hello toast!";
    int duration = Toast.LENGTH_SHORT;

    Toast toast = Toast.makeText(context, text, duration);
    toast.show();

}

//////end class

}
