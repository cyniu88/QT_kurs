//
//AndroidHelper.java
//
package org.qtproject.example.Chronometer;

import org.qtproject.qt5.android.QtNative;
import android.app.Notification;
import android.app.NotificationManager;

import android.content.Context;
import android.os.Vibrator;
import android.app.Activity;
import android.os.Bundle;
import android.widget.Toast;

import android.os.BatteryManager;

import android.content.Intent;
import android.content.IntentFilter;


public class AndroidHelper extends org.qtproject.qt5.android.bindings.QtActivity
{

public static Vibrator m_vibrator;

public static NotificationManager m_notificationManager;
public static Notification.Builder m_builder;

public static BatteryManager battery;

public static AndroidHelper m_instance_n;

public static AndroidHelper m_instance;

public static Intent m_sendIntent;

public AndroidHelper()
{
m_instance_n = this;
}

public static void vibrate(int x)
{
if (m_vibrator == null)
{
if (m_instance_n != null)
{
m_vibrator = (Vibrator) m_instance_n.getSystemService(Context.VIBRATOR_SERVICE);
m_vibrator.vibrate(x);
}

   }
   else m_vibrator.vibrate(x);

}

public static void makeToast(final String s)
    {
        m_instance_n.runOnUiThread(new Runnable() {
                 public void run() {
                     Toast.makeText(m_instance_n.getApplicationContext(),
                                    s,
                                    Toast.LENGTH_SHORT).show();
                 }
              });
    }

public static void notify(final String s)
    {
        if (m_notificationManager == null) {
            m_notificationManager = (NotificationManager)m_instance_n.getSystemService(Context.NOTIFICATION_SERVICE);
            m_builder = new Notification.Builder(m_instance_n);

            m_builder.setContentTitle("A message from Qt!");
        }
        m_builder.setContentText(s);
        m_notificationManager.notify(1, m_builder.build());
    }

public static void share(String text) {
    if (QtNative.activity() == null)
     //   return false;
   // Intent sendIntent = new Intent();
    m_sendIntent.setAction(Intent.ACTION_SEND);
    m_sendIntent.putExtra(Intent.EXTRA_TEXT, text );
    m_sendIntent.setType("text/plain");
    // Verify that the intent will resolve to an activity
    if (m_sendIntent.resolveActivity(QtNative.activity().getPackageManager()) != null) {
        QtNative.activity().startActivity(m_sendIntent);
      //  return true;
    }
   // return false;
}

//////end class

}
