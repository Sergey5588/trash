//simple movement depending on the angle of rotation for Unity
using System.Collections;
using System.Collections.Generic;
using UnityEngine;


public class Player : MonoBehaviour
{
    private Rigidbody rb;
    public float speed = 5.0f;
    
    void Start()
    {
        rb = gameObject.GetComponent<Rigidbody>();
    }
    
    
    void Update()
    {
        Debug.Log(gameObject.transform.rotation.y);
        gameObject.transform.Rotate(new Vector3(0,2.0f*Input.GetAxis("Horizontal")));
        
        rb.velocity = new Vector3(Mathf.Sin(gameObject.transform.rotation.y *Mathf.PI) * Input.GetAxis("Vertical")*speed, 0, Mathf.Cos(gameObject.transform.rotation.y* Mathf.PI) * Input.GetAxis("Vertical")*speed);
        
        
    }
}
