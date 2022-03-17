using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Player : MonoBehaviour
{
    [SerializeField] GameObject _bg = null;
    private SpriteRenderer BG;
    private float pointX = 0;

    void Start()
    {
        BG = _bg.transform.GetChild(0).GetComponent<SpriteRenderer>();
        float pointX = _bg.transform.position.x + (BG.size.x / 2);
    }

    void Update()
    {
        float Hor = Input.GetAxis("Horizontal");
        float Ver = Input.GetAxis("Vertical");
        //GetAxisRaw : -1, 0, 1�� ���

        transform.Translate(Hor * 5.0f * Time.deltaTime, Ver * 5.0f * Time.deltaTime, 0.0f);
        float xlimit = Camera.main.transform.position.x +
            Camera.main.aspect * Camera.main.orthographicSize;

        if (xlimit > pointX - 5)
        {
            GameObject Obj = Instantiate(_bg);
            Vector3 vPos = new Vector3(pointX + BG.size.x, 0.0f, 0.0f);
            pointX += BG.size.x;
            Obj.transform.position = vPos;
        }
    }
}
