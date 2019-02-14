# migration
source code migration

# ����

## gcc

- gcc log

  - 3.7 Options to Control Diagnostic Messages Formatting
    - https://gcc.gnu.org/onlinedocs/gcc/Diagnostic-Message-Formatting-Options.html
    - fdiagnostics-format=FORMAT
      - json / text

  - 3.8 Options to Request or Suppress Warnings
    - https://gcc.gnu.org/onlinedocs/gcc/Warning-Options.html#Warning-Options

    - Wall
    - Wextra

- option

  - �}�N���̎g�p�ƃf�o�b�O�Ɋւ���I�v�V����
    - -Dmacro, -Dmacro=value [�m���Ă�ƕ֗�]
      �Վ��Ƀ}�N�����`����B
    - -Umacro
      - �Վ��Ƀ}�N���𖢒�`�ɂ���B
    - -E
      - �}�N���̓W�J����������B
    - -C (with -E)
      - �}�N���̓W�J���������s�F�R�����g�͎c���B
    - -P (with -E)
      - �}�N���̓W�J���������s�F#line �s�𐶐����Ȃ��B
    - -M (with -E)
      - �\�[�X�� include ����Ă���t�@�C������\��
    - -MM (with -E)
      - �\�[�X�� include ����Ă���t�@�C������\�����邪�A�V�X�e�����ŏ�����include���Ă�����̂͏����B
    - -dM (with -E)
      - �\�[�X���ň�x�ł��Q�Ƃ��ꂽ�}�N����`��\��
    - -dD (with -E)
      - �\�[�X���̃}�N����`�A����уv���g�^�C�v��`��\��
