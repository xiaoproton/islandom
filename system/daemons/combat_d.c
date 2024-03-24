#include <ansi.h>

// 战斗伤害类型
#define TYPE_N 0 // 普通攻击
#define TYPE_C 1 // 会心一击

// 攻击信息
nosave string *attack_msg = ({
    "$ME ignored the action of $YOU, attacked aggresively.",
    "$ME watching each step of $YOU, suddenly attacked.",
    "$ME starting slowly but accelerated dramatically to attack.",
});
// 防御攻击信息
nosave string *guard_msg = ({
    "But the attack from $ME was blocked by $YOU.",
    "But $YOU foresaw the action and confidently stop the attack from $ME.",
});
// 躲避攻击信息
nosave string *dodge_msg = ({
    "But the attack from $ME was dodged by $YOU swiftly.",
    "But $YOU jumped up and down to avoid the attack from $ME.",
    "But $YOU turned around to skip the attack from $ME.",
});
// 伤害信息
string damage_msg(int damage, int type)
{
    if (damage == 0)
    {
        switch (random(3))
        {
        case 1:
            return element_of(guard_msg);
        case 2:
            return element_of(dodge_msg);
        default:
            return "But the attack from $ME was too weak to hurt $YOU at all.";
        }
    }

    switch (type)
    {
    case TYPE_C:
        return YEL "$ME hit a [WAEK POINT] of $YOU, causing " + damage + " damage.";
    default:
        return "$ME caused to $YOU  " + damage + " damage.";
    }
}

string death_msg()
{
    switch (random(3))
    {
        case 1:
            return "$YOU are almost dead during for fighting with $ME.";
        case 2:
            return "$YOU have sacrificed your health for the Queens colony and the Brood.";
        default:
            return "$YOU are almost killed by $ME. All your vision turns into darkness.";
    }

}

void create()
{
}

// 攻击处理
void do_attack(object me, object victim)
{
/**
 * 物理伤害计算方法
 */
    int powerme, damage, powervic, random, attack_type = TYPE_N;

    powerme = me->query("power");
    powervic = victim->query("power");
    //debug_message(sprintf("powerme %d powervic %d",powerme,powervic));
    if(powerme>=powervic)
        damage = log2(powerme - powervic)+1;
    else
        damage = 1;

    /**
     * 会心伤害（暴击）无视防御
     * [会心伤害基础值]=攻击力
     */
    if (random(100) < 10)
    {
        attack_type = TYPE_C;
    }
    // 伤害波动
    random = damage / 3 + 2;
    if (random(2))
    {
        damage += random;
    }
    else
    {
        damage -= random;
    }

    if (damage <= 0)
    {
        damage = random(2);
    }
    //debug_message(sprintf("victim %O",victim));
    //debug_message(sprintf("damage %d",damage));
    victim->set("hp", victim->query("hp") - damage);
    msg("warning", damage_msg(damage, attack_type), me, victim);
    if(to_int(victim->query("hp"))<=0)
    {
        msg("danger", death_msg(), me, victim);
        victim->die();
    }
}

// 战斗回合处理
void fight(object me, object victim)
{
    // 避免隔空战斗
    if (environment(me) != environment(victim))
    {
        return;
    }

    if (!victim->is_fighting(me))
    {
        victim->fight(me);
    }

    msg("info", element_of(attack_msg), me, victim);
    do_attack(me, victim);
}
