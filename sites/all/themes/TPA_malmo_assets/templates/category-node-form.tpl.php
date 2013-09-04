<section>
	<?php if( $form ): ?>
		<div class="control-group">
			<label class="control-label" for="person-name"><?php print $title_string; ?></label>
			<div class="controls">
				<?php print $title_input; ?>
			</div>
		</div>
		<?php //print drupal_render_children( $form ); ?>
	<?php endif; ?>
</section>