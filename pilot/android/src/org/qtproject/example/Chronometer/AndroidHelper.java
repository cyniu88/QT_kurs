//
//AndroidHelper.java
//
package org.qtproject.example.Chronometer;

import android.app.Notification;
import android.app.NotificationManager;

import android.content.Context;
import android.os.Vibrator;
import android.app.Activity;
import android.os.Bundle;


import android.widget.Toast;


public class AndroidHelper extends org.qtproject.qt5.android.bindings.QtActivity
{

public static Vibrator m_vibrator;

private static NotificationManager m_notificationManager;
private static Notification.Builder m_builder;


private static AndroidHelper m_instance_n;

public static AndroidHelper m_instance;

public AndroidHelper()
{
m_instance = this;
m_instance_n = this;
}

public static void vibrate(int x)
{
if (m_vibrator == null)
{
if (m_instance != null)
{
m_vibrator = (Vibrator) m_instance.getSystemService(Context.VIBRATOR_SERVICE);
m_vibrator.vibrate(x);
}

   }
   else m_vibrator.vibrate(x);

}






public static int test(int n)
{
    //Toast.makeText(Context.TOAST_SERVICE,   "Button is clicked", Toast.LENGTH_LONG).show();
    return n*n;
}
public static int fibonacci(int n)
   {


        if (n < 2)
             return n;
       return fibonacci(n-1) + fibonacci(n-2);
    }

public static int notify(String s)
    {
        if (m_notificationManager == null) {
            m_notificationManager = (NotificationManager) m_instance_n.getSystemService(Context.NOTIFICATION_SERVICE);
            m_builder = new Notification.Builder(m_instance_n);
           // m_builder.setSmallIcon(R.drawable.icon);
            m_builder.setContentTitle("A message from Qt!");
        }

        m_builder.setContentText(s);
        m_notificationManager.notify(1, m_builder.build());
        return 1;
    }


//////end class

}
